cd .. ; scons platform=linux -j8 ; cd project ; ./godot-headless.64 --export-pack "Linux/X11" "server.pck" ; ./godot-server.64 "server.pck"