I placed each struct in a separate file, so all those have to be
included for the program to compile. Unfortunately, the automatic
marking system does not recognize those files, so you'll have to
compile manually.

I wrote a make file to speed up the development cycle:

	$ cd ~/
    $ make
