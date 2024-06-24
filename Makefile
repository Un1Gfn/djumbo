
init:
	$(MAKE) purge
	makepkg -f -i
	@echo
	-rm -r pkg/ 
	@echo
	makepkg --printsrcinfo >.SRCINFO
	@echo

incr:
	@# MAKEPKG_SKIP_PACKAGE=1 makepkg -f
	cmake --build src/build -j4

purge:
	@echo
	-rm -rf djumbo*.pkg.* pkg/ src/build
	@echo
	git status --ignored
	-sudo pacman -Rc djumbo
	@echo

