import bake.build;
import std;

int main() {
    bake::Builder b;
    const auto upstream = std::string(b.dep_src_dir("upstream"));

    // src/lib/Makefile.inc (used by CMake) lists these production units.
    b.sources({upstream + "/src/lib/*.c",
               upstream + "/src/lib/dsa/*.c",
               upstream + "/src/lib/event/*.c",
               upstream + "/src/lib/legacy/*.c",
               upstream + "/src/lib/record/*.c",
               upstream + "/src/lib/str/*.c",
               upstream + "/src/lib/util/*.c"})
        .include_dirs({upstream + "/include", upstream + "/src/lib",
                       upstream + "/src/lib/include", "config"})
        .public_headers(upstream + "/include");

    return b.build();
}
