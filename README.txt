# Install
Only one architecture of the libraries can be installed in system at a time.
So if you have installed these libraries for 32bit and then you want to
build 64bit wine. You need to install 64bit libraries to override to 32bit
before you can do that.

Enter the correct dir for architecture and sudo make install -j $(nproc)
Sometimes 64bit install may fail for nettle if 32bit was installed.
This is a problem I have been reluctant to fix.
In this case, enter 64bit dir, rm nettle.ok && sudo make nettle.ok -j $(nproc) && sudo make install -j $(nproc)

# Clean for rebuild in case anything goes wrong.
sudo make clean

# Build wine for debug
# 64 bit
./configure CFLAGS="-g -Og -fno-optimize-sibling-calls -fno-omit-frame-pointer -fno-inline" --enable-win64 && make -j $(nproc)
# 32 bit
./configure CFLAGS="-g -Og -fno-optimize-sibling-calls -fno-omit-frame-pointer -fno-inline" && make -j $(nproc)

# Uninstall
Currently no uninstall. You can override the installed libraries with another architeture by make clean && sudo make install -j $(nproc)
