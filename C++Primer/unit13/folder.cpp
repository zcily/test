#include "folder.h"

namespace MyMessage
{
	//----------------------class message---------------------------//
	Message::Message(const Message& mg)
		:textContents(mg.textContents)
		,folders(mg.folders)
	{
			
	}

	void Message::add_to_folders(const Message& mg)
	{
		for(set<Folder *>::iterator it = mg.folders.begin(); it != mg.folders.end(); ++it)	{
			(*it)->addMsg(this);	
		}
	}

	void Message::remove_from_folders()
	{
		for(set<Folder *>::iterator it = this->folders.begin(); it != this->folders.end(); ++it) {
			(*it)->remMsg(this);	
		}
	}

	Message::~Message()
	{
		remove_from_folders();	
	}

	Message& Message::operator=(const Message&mg)
	{
		remove_from_folders();	
		this->textContents = mg.textContents;
		this->folders = mg.folders;	
		add_to_folders(mg);

		return *this;
	}

	void Message::saveMessage(Folder &fd)
	{
		folders.insert(&fd);
		fd.addMsg(this);
	}

	void Message::removeMessage(Folder &fd)
	{
		folders.erase(&fd);	
		fd.remMsg(this);
	}

	//----------------------class folders---------------------------//	
	
	Folder::Folder(const Folder& fd)
	{
		this->messages = fd.messages;	
		put_folder_to_message(fd);
	}

	Folder& Folder::operator=(const Folder& fd)
	{
		remove_folder_from_message();	
		this->messages = fd.messages;
		put_folder_to_message(fd);

		return *this;
	}

	Folder::~Folder()
	{
		remove_folder_from_message();	
	}
	
	void Folder::put_folder_to_message(const Folder &fd)
	{
		for(set<Message*>::iterator it = fd.messages.begin(); it != fd.messages.end(); ++it) {
			(*it)->saveMessage(*(const_cast<Folder*>(&fd)));
		}
	}

	void Folder::remove_folder_from_message()
	{
		for(set<Message*>::iterator it = this->messages.begin(); it != this->messages.end(); ++it)	
			(*it)->removeMessage(*this);
	}

	void Folder::addMsg(const Message* mg)
	{
		this->messages.insert(const_cast<Message*>(mg));	
	}

	void Folder::remMsg(const Message* mg)
	{
		this->messages.erase(const_cast<Message*>(mg));	
	}
}
