# Maintainer: Your Name <youremail@domain.com>
pkgname=djumbo
pkgver=1
pkgrel=1
pkgdesc="tools bundle with Qt GUI - CsappCalc CacheAway Jangaehwepi ..."
arch=(x86_64)
url="https://github.com/Un1Gfn/djumbo"
license=(AGPL-3.0-or-later)
depends=(gcc-libs glibc qt6-base)
makedepends=(cmake)
options=(!strip libtool staticlibs emptydirs !zipman !debug !lto !purge)
install=

build() {
	[ "$PWD" = "$srcdir" ]
	cmake -DCMAKE_PROJECT_DESCRIPTION="$pkgdesc" -B ./build -S .
	# cmake --build build --target clean
	cmake --build build
	# if [ -v MAKEPKG_SKIP_PACKAGE ]; then
	# 	msg "Terminate after build()."
	# 	exit 0
	# fi
}

package() {
	[ "$PWD" = "$srcdir" ]
	export CMAKE_INSTALL_MODE=ABS_SYMLINK
	export DESTDIR="$pkgdir"
	cmake --install ./build
}

