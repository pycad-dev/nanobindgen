"""Setuptools install script."""

import os
import platform
import shutil
import subprocess
import tempfile

import setuptools.command.build

from setuptools import Command
from setuptools.command.build_py import build_py
from wheel.bdist_wheel import bdist_wheel as _bdist_wheel


def get_shared_lib_extension():
    """Get the shared library extension on this platform."""
    system = platform.system()
    if system == "Linux":
        return ".so"
    elif system == "Darwin":
        return ".dylib"
    elif system == "Windows":
        return ".dll"
    else:
        raise RuntimeError("Unsupported system: {}".format(system))


class CustomBuildPy(build_py):
    """Custom build command to build tree-sitter-doxygen and copy the shared library."""

    def run(self):
        """Build tree-sitter-doxygen."""
        ext = get_shared_lib_extension()
        with tempfile.TemporaryDirectory() as tmpdir:
            build_path = tmpdir + "doxygen" + ext
            subprocess.run(
                [
                    "tree-sitter",
                    "build",
                    "-o",
                    build_path,
                    "./tree-sitter-doxygen",
                ],
                check=True,
            )

            # Copy the shared library to the package directory
            dst = os.path.join(self.build_lib, "nanobindgen", "doxygen" + ext)
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            shutil.copy2(build_path, dst)

        super().run()


class bdist_wheel(_bdist_wheel):
    def finalize_options(self):
        # Mark the wheel as non-pure (platform-specific)
        super().finalize_options()
        self.root_is_pure = False

    def get_tag(self):
        python, abi, plat = super().get_tag()
        return "py39", "none", plat


setuptools.setup(
    cmdclass={
        "build_py": CustomBuildPy,
        "bdist_wheel": bdist_wheel,
    }
)
