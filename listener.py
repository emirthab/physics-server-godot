from flask import Flask, request
from werkzeug.utils import secure_filename
import os
import subprocess

app = Flask(__name__)


def pushCommit():
    subprocess.call("git push origin main")

def commit():
    subprocess.call('git commit -a -m "Commit  from REST API" ')

def pull():
    subprocess.call("git pull")
    
def restartOrStartServer():
    os.system("killall godot-server.64")
    os.system('"./godot-server.64" "./server/project/server.pck"')

@app.route("/data", methods=["GET"])
def data():
    

if __name__ == "__main__":
    app.run(port=3434,debug=True)
