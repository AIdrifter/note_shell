# find
find . -type f -name "*.ori" -exec rm -f {} \;
find . -type f -name "*.bak" -exec rm -f {} \;
find . -type f -name "*.o" -exec rm -f {} \;
find . -type f -name "*.so" -exec rm -f {} \;

