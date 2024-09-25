"""Setuptools install script."""

import platform
import subprocess

import setuptools.command.build
from setuptools import Command


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


setuptools.command.build.build.sub_commands.append(("build_treesitter_doxygen", None))
setuptools.setup(cmdclass={"build_treesitter_doxygen": BuildTreesitterDoxygen})