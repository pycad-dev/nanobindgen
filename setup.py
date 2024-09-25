"""Setuptools install script."""

import platform
import subprocess

import setuptools.command.build
from setuptools import Command
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


class BuildTreesitterDoxygen(Command):
    """Build the tree-sitter-doxygen parser."""

    def initialize_options(self):  # noqa: D102
        pass

    def finalize_options(self):  # noqa: D102
        pass

    def run(self):
        """Build tree-sitter-doxygen."""
        ext = get_shared_lib_extension()
        subprocess.run(
            [
                "tree-sitter",
                "build",
                "-o",
                "src/nanobindgen/doxygen" + ext,
                "./tree-sitter-doxygen",
            ],
            check=True,
        )


class bdist_wheel(_bdist_wheel):
    def finalize_options(self):
        # Mark the wheel as non-pure (platform-specific)
        super().finalize_options()
        self.root_is_pure = False

    def get_tag(self):
        python, abi, plat = super().get_tag()
        return "py39", "none", plat


setuptools.command.build.build.sub_commands.append(("build_treesitter_doxygen", None))
setuptools.setup(
    cmdclass={
        "build_treesitter_doxygen": BuildTreesitterDoxygen,
        "bdist_wheel": bdist_wheel,
    }
)
