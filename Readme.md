#ZenOS

ZenOS is an Operating System with native WebAssembly support.

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

## Compile

```sh
make
```

## Run

```sh
qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso -serial kernel.log
```
