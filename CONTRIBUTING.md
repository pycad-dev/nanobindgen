# Releasing a new version

Nanobindgen follows the semantic versioning standard.

1. **Update `pyproject.toml`**:
   - Edit the `version` field in `pyproject.toml` to reflect the new version.

2. **Commit the Version Change**:
   - Commit the updated `pyproject.toml` file with a message like `chore: bump version to x.y.z`.

3. **Create the Git Tag**:
     ```bash
     git tag v1.0.1
     git push origin v1.0.1
     ```