1. Put your root, certificate and private key in the folder called 'certificates'
2. Open Python Code in editor
3. Copy the name of the file that ends with 'certificate.pem.crt' assign the name to PATH_TO_CERT
4. Copy the name of the file that ends with 'private.pem.key' assign the name to PATH_TO_KEY
5. Copy the name of the file that ends with 'RootCA3.pem' assign the name to PATH_TO_ROOT
6. Change TOPIC to your desired topic name

If the following exception occurs:

AWS_ERROR_MQTT_UNEXPECTED_HANGUP: The connection was closed unexpectedly.

then disable certificate and then enable your certificate
try executing the python code again
