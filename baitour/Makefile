Server := myServer
client := myClient
test := soapTester
      
#your gsoap install directory
GSOAP_DIR=/home/daniel/Documents/gsoap-2.8
     
#compiler
CORSS_COMPILER = 
G++ :=$(CORSS_COMPILER)g++
      
#flags
LIBS:=  -lpthread -lm
INCLS := -I ./ -I $(GSOAP_DIR)/gsoap
CFLAGS := -O2 -Wall -Wno-deprecated-declarations
COM_SOURCES := soapC.cpp  $(GSOAP_DIR)/gsoap/stdsoap2.cpp
COM_OBJS := $(COM_SOURCES:.cpp=.o)
OBJ_SOURCES := $(server).cpp soapServer.cpp $(client).cpp soapClient.cpp $(test).cpp
OBJS := $(OBJ_SOURCES:.cpp=.o) $(COM_OBJS)
      
#MAKE
.PHONY: all wsdl gsoap server client test
all: test
server: wsdl gsoap makeServer 
client: wsdl gsoap makeClient
test: wsdl gsoap makeTest
      
      
#files
WSDL_FILES := temp.h
GSOAP_FILES := soapClient.cpp soapServer.cpp soapC.cpp soapH.h soapStub.h

WSDL_SOURCE := $(wildcard *.wsdl)
ifeq ( , $(WSDL_SOURCE))
#WSDL_SOURCE := $(GSOAP_DIR)/gsoap/WS/WS-Discovery.wsdl
WSDL_SOURCE := /home/daniel/Documents/qqWebService/qqOnlineWebService.wsdl
endif
      
TYPEMAP = $(wildcard *typemap.dat)
ifeq ( , $(TYPEMAP))
TYPEMAP = $(GSOAP_DIR)/gsoap/typemap.dat
endif
      
wsdl:
ifneq ($(WSDL_FILES), $(wildcard $(WSDL_FILES)))
	$(GSOAP_DIR)/gsoap/wsdl2h -P -t $(TYPEMAP) $(WSDL_SOURCE) -o temp.h
endif
      
gsoap:
ifneq ($(GSOAP_FILES), $(wildcard $(GSOAP_FILES)))
	$(GSOAP_DIR)/gsoap/src/soapcpp2 -x -L -T -I $(GSOAP_DIR)/gsoap/import:$(GSOAP_DIR)/gsoap $(WSDL_FILES)
endif

makeServer:$(server).o soapServer.o $(COM_OBJS)
	$(G++) $(INCLS) $(CFLAGS) -o $(server) $^ $(LIBS)

makeClient:$(client).o soapClient.o $(COM_OBJS) 
	$(G++) $(INCLS) $(CFLAGS) -o $(client) $^ $(LIBS)
      
makeTest:$(test).o soapServer.o soapClient.o $(COM_OBJS)
	$(G++) $(INCLS) $(CFLAGS) -o $(test) $^ $(LIBS)
      
      
$(OBJS) :%.o:%.cpp
	$(G++) $(INCLS) $(CFLAGS) -o $@ -c $^ 
      
#clean
clean:
	@rm -rfv *.o *~ *Proxy.h *Object.h $(server) $(client) $(test)
      
deepClean:
	@rm -rfv *.o *~ *Proxy.h *Object.h $(server) $(client) $(test) *.nsmap $(GSOAP_FILES) $(WSDL_FILES) soapTester.cpp
