# Create a directory with hello.c in it
if [ -e autodemo ]; then rm -r autodemo; fi
mkdir -p autodemo
cd autodemo
cat > hello.c <<\
"----"
#include <stdio.h>
int main () { printf("Hi.\n"); }
----

# Create a Makefile.am
cat > Makefile.am <<\
"----"
bin_PROGRAMS=hello
hello_SOURCES=hello.c
----

# Create a configure.scan
autoscan

# Edit configure.scan
sed -e 's/FULL-PACKAGE-NAME/hello/' \
    -e 's/VERSION/1/' \
    -e 's|BUG-REPORT-ADDRESS|/dev/null|' \
    -e '10i\
AM_INIT_AUTOMAKE' \
    < configure.scan > configure.ac

# Create standard packing files required by autotools
touch NEWS README AUTHORS ChangeLog

autoreconf -iv
./configure
make distcheck