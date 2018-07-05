LIB=libstrongexit.so

all: $(LIB) mbrola

$(LIB): strongexit.c
	$(CC) $(CFLAGS) $< -o $@ -shared -fPIC $(LDFLAGS)

mbrola: mbrola.in
	sed -e 's/@DEB_HOST_MULTIARCH@/$(shell dpkg-architecture -qDEB_HOST_MULTIARCH)/g' < $< > $@
	chmod +x $@

clean:
	rm -f $(LIB) mbrola
