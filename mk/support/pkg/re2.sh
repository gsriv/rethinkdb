
version=20140111

src_url=http://re2.googlecode.com/files/re2-$version.tgz

pkg_install () {
    pkg_copy_src_to_build
    pkg_make install prefix="$install_dir" CXXFLAGS="-O3" LDFLAGS="$(PTHREAD_LIBS)"
}
