# ZenOs

ZenOs is an Operating System with native WebAssembly support.

## Docker build instructions

```sh
docker build buildenv -t zenos
```

### Linux or Macos
```sh
docker run --rm -it -v $(pwd):/root/env zenos
```

### Windows
```sh
docker run --rm --it -v %cd%:/root/env zenos
```

## Using Podman

Just replace `docker` with `podman` in the above commands.

## Compile x86_64

```sh
make build-x86_64
```
