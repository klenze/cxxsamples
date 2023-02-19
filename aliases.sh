# to be sourced with bath

alias vg="valgrind --leak-check=full --suppressions=$ROOTSYS/etc/valgrind-root.supp"

alias rootcompile="$(root-config --cxx --cflags --ldflags --libs --glibs) -g -fuse-ld=gold -D_GLIBCXX_ASSERTIONS=1 "
