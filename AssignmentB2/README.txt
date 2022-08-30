I placed each struct in a separate file, so all those have to be
included for the program to compile. Unfortunately, the automatic
marking system does not recognize those files, so you'll have to
compile manually.

The project is compiled via CMake:

    $ cd ~/stage2
    $ cmake ./
    $ cmake --build ./
