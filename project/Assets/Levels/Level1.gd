extends Node2D

var server : WebSocketServer


# Called when the node enters the scene tree for the first time.
func _ready():
	server.listen(3636)


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
