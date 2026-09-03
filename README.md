# c-ares for bake

[c-ares](https://c-ares.org) 1.34.8, packaged for
[bake](https://github.com/Ariaszzzhc/bake). Static asynchronous DNS resolver
library, C.

## Use

```bash
bake add https://github.com/bake-pkgs/c-ares --tag v1.34.8 c-ares
```

```toml
[dependencies]
c-ares = { url = "https://github.com/bake-pkgs/c-ares", tag = "v1.34.8" }
```

```c
#include <ares.h>
```

Nothing is vendored here: the pinned upstream release archive is fetched and
compiled from source on every target. `build.cpp` follows c-ares'
`src/lib/Makefile.inc` source list. Its generated Unix configuration is
represented by `config/ares_config.h`; Windows uses c-ares' maintained
`config-win32.h`. `CARES_STATICLIB` and the required Windows system libraries
flow transitively to consumers. License: MIT (upstream).
