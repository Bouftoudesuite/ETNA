SRC		= ./src/client/client.py
DEST		= /usr/local/bin/prepget
LOCAL		= /usr/local/prepget
PATCH		= ./src/client/patch.py
APT		= apt-get -y install
CHMOD		= chmod a+x
PYTHON_INSTALL	= python -m pip install
RM		= rm -rf

all:
		$(APT) python
		$(APT) python-pip
		$(PYTHON_INSTALL) requests	
		cp $(SRC) $(DEST)
		mkdir $(LOCAL)
		mkdir $(LOCAL)/paquet
		mkdir $(LOCAL)/tmp
		$(CHMOD) $(DEST)
		python $(PATCH)

clean:
		$(RM) $(DEST)
		$(RM) $(LOCAL)

re:		clean all
