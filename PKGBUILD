pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
groups=(custom)
license=('MIT')
depends=('libx11' 'pango')
options=(zipman)
provides=('dwm')
conflicts=('dwm-pango')
_source=("http://dl.suckless.org/$pkgname/$pkgname-$pkgver.tar.gz"
         'config.h'
         'buildflags.diff'
        )
_patches=(
         00-dwm-6.0-pertag2.diff
         01-dwm-6.0-pango.diff
         02-dwm-6.0-urgentcolor.diff
         03-dwm-6.0-hideempty.diff
         04-dwm-6.0-chat.diff
         05-dwm-6.0-push.diff
         06-dwm-6.0-cycle.diff
         07-dwm-6.0-singularborders.diff
         08-dwm-6.0-attachaside.diff
         10-dwm-6.0-monocleindicator.diff
         11-dwm-6.0-focusfollowmousetag.diff
         12-dwm-6.0-removeunfunc.diff
         13-dwm-6.0-xkeycodetokeysymfix.diff
         14-dwm-6.0-smfact.diff
         15-dwm-6.0-netwmdemandsattention.diff
         16-dwm-6.0-zoomswap.diff
         )
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '1dcabacba391c04768bcd1705f34b777'
         '47b8cca84c61529266614d2a480b9e9d'
         'af6c17f901ad910f1361ce1c25070b03'
         'e06836181b05e84e2fd5d47ec6724707'
         'd96ec7509cfe6be1bfc6d1c9e149a26d'
         '41898ed919e7bdd484096feda2f4ee2f'
         'f099928846b74a600e4b24d7cfb61656'
         '455be45ad6a061f73faa8438ee4c917f'
         'b50db47f358e21b2c58399f6424d339a'
         'cc50b186ae38a0cb583949a6bd45631c'
         'bc7d12946c77113a7e9a73c99ef81b9f'
         '161ede77c64f21555db333f2212e9533'
         'cc215a75d74f8dc442ea23b151eb7e67'
         '29a5c029b9029edbd8feea21265bae30'
         'e3c4e9039974a97803d0071a7f0fb762'
         '99c608a822f3b43a065093ea7b8fee56'
         'fcc18a0c8a4b0183127e1c7c6da6fa86'
         '6e94ec1bd6b4cb29eebffd5e7dd686f1')
source=(${_source[@]} ${_patches[@]})



build() {
  cd $srcdir/$pkgname-$pkgver
  cp $srcdir/config.h .

  patch -Np1 config.mk $srcdir/buildflags.diff
  for PATCH in "${_patches[@]}"; do
    msg "${PATCH##*/}" && patch -Np1 dwm.c "$srcdir/${PATCH##*/}"
  done

  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  cd $srcdir/$pkgname-$pkgver

  make PREFIX=/usr DESTDIR=$pkgdir install
  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
}
