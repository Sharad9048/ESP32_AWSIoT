# ESP32_AWSIoT
## AWSCertKeyHeaderFileCreator.py
1. Put your downloaded RootCA, Certificate, private key in the folder called certificates
2. Execute Python Code 'AWSCertKeyHeaderFileCreator.py' which will create a header file called 'myCertificateData.h' containing Your Certificate, root and private key data
3. Move 'myCertificateData.h' file to the folder called AWSIoTPublish replace it with the older one

## Test_AWS_IoT_with_Python
The folder containsPyhton code to test your AWS IoT
