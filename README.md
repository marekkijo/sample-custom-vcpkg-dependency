# sample-custom-vcpkg-dependency

This is a sample depenedency with intention to be used as a vcpgk package.

## Additional information

### vcpkg.json dependencies of this project

'host' == true means that the dependency is only used during the build process and is not required at runtime:

```bash
  "dependencies": [
    {
      "name": "vcpkg-cmake",
      "host": true
    },
    {
      "name": "vcpkg-cmake-config",
      "host": true
    }
  ]
```

here additional dependencies are added to the project - these are required at runtime:

```bash
  "dependencies": [
    "fmt",
    "opengl",
    {
      "name": "vcpkg-cmake",
      "host": true
    },
    {
      "name": "vcpkg-cmake-config",
      "host": true
    }
  ]
```
