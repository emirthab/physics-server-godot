import requests
ip = "45.141.149.120:3434"
import time

with open("./project/server.pck", "rb") as a_file:
	file_dict = {"file": a_file}
	response = requests.post("http://"+ ip +"/data", files=file_dict)
	print(response.text)
	try:
		requests.get("http://"+ ip + "/stopserver",timeout=1)
		time.sleep(0.2)
		response = requests.get("http://"+ ip + "/startserver", timeout=1)
	except:
		print("")