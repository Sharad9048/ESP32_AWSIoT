# ESP32_AWSIoT
## AWSCertKeyHeaderFileCreator.py
1. Put your downloaded RootCA, Certificate, private key in the folder called certificates
2. Execute Python Code 'AWSCertKeyHeaderFileCreator.py' which will create a header file called 'myCertificateData.h' containing Your Certificate, root and private key data
3. Move 'myCertificateData.h' file to the folder called AWSIoTPublish replace it with the older one

## Test_AWS_IoT_with_Python
The folder contains Pyhton code to test your AWS IoT

## AWSIoTPublish/awsFunction.h
1. Make changes to ThingName with name of the thing you created.
2. Make changes to endPoint with the end point URL in AWIoT Settings menu.
3. Make changes to topicName with the topic name that you desire.
