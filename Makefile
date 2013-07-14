
all: build

build:
	makepkg -f --skipchecksums

install:
	sudo pacman -U dwm-6.0-1-x86_64.pkg.tar.xz
