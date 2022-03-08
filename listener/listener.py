from flask import Flask, request
from werkzeug.utils import secure_filename
import os

app = Flask(__name__)

@app.route("/data", methods=["POST"])
def data():
	if "file" not in request.files:
		return "No file part."
	file = request.files["file"]
	if file.filename != "server.pck":
		return "No selected file."
	else:
		filename = secure_filename(file.filename)
		file.save(os.getcwd()+"/"+filename)
		return "SUCCESS"

@app.route("/startserver", methods=["GET"])
def startserver():
	os.system('"./godot-server.64" "./server.pck"')

@app.route("/stopserver", methods=["GET"])
def stopserver():
	os.system("killall godot-server.64")

if __name__ == "__main__":
	app.run(port=3434)