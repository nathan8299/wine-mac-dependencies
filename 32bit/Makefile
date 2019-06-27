all: install

libpng.ok: libpng-1.6.35
	-mkdir $<.build
	cd $<.build && CFLAGS="-arch i386" LDFLAGS="-arch i386" ../$</configure && cd ..
	$(MAKE) -C $<.build install
	touch $@

jpeg.ok: jpeg-9a
	-mkdir $<.build
	cd $<.build && CFLAGS="-arch i386" LDFLAGS="-arch i386" ../$</configure && cd ..
	$(MAKE) -C $<.build install
	touch $@

freetype.ok: freetype-2.6.2 libpng.ok jpeg.ok
	-mkdir $<.build
	cd $<.build && CFLAGS="-arch i386" LDFLAGS="-arch i386" ../$</configure && cd ..
	$(MAKE) -C $<.build
	$(MAKE) -C $<.build install
	touch $@

nettle.ok: nettle-3.4
	-mkdir $<.build
	cd $<.build && CFLAGS="-arch i386" LDFLAGS="-arch i386" ../$</configure && cd ..
	$(MAKE) -C $<.build install
	touch $@

gmp.ok: gmp-6.1.2 nettle.ok
	-mkdir $<.build
	cd $<.build && CFLAGS="-arch i386" LDFLAGS="-arch i386" ABI=32  ../$</configure && cd ..
	$(MAKE) -C $<.build install
	touch $@

libffi.ok: libffi-3.2.1
	-mkdir $<.build
	cd $<.build && CFLAGS="-arch i386" LDFLAGS="-arch i386" ../$</configure && cd ..
	$(MAKE) -C $<.build install
	touch $@

libtasn1.ok: libtasn1-4.13
	-mkdir $<.build
	cd $<.build && CFLAGS="-arch i386" LDFLAGS="-arch i386" ../$</configure && cd ..
	$(MAKE) -C $<.build install
	touch $@

p11-kit.ok: p11-kit-0.23.14 libffi.ok libtasn1.ok
	-mkdir $<.build
	cd $<.build && CFLAGS="-arch i386" LDFLAGS="-arch i386" ../$</configure --without-trust-paths && cd ..
	$(MAKE) -C $<.build install
	touch $@

gnutls.ok: gnutls-3.5.19 gmp.ok nettle.ok p11-kit.ok
	-mkdir $<.build
	cd $<.build && CFLAGS="-arch i386" LDFLAGS="-arch i386" ../$</configure --disable-hardware-acceleration --with-included-unistring && cd ..
	$(MAKE) -C $<.build install
	touch $@

install: libpng.ok jpeg.ok freetype.ok nettle.ok gmp.ok libffi.ok libtasn1.ok p11-kit.ok gnutls.ok
	echo "Installed Wine 32bit dependencies"

clean:
	-rm -rf *.ok *.build
