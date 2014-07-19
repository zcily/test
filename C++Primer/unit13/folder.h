#ifndef __FOLDER_H__
#define __FOLDER_H__

#include <string>
#include <set>

using namespace std;

namespace MyMessage
{
	class Folder;
	class Message 
	{
		friend class Folder;
		
		public:
			Message(const string& str = "")	
				: textContents(str)
			{
			}

			Message(const Message&);
			Message& operator=(const Message&);
			~Message();
			
			void saveMessage(Folder&);
			void removeMessage(Folder &);


//			void saveFolder(Folder&);
//			void removeFolder(Folder&);

		private:
			string textContents;
			set<Folder*> folders;
			
			void remove_from_folders();
			void add_to_folders(const Message &);
	};

	class Folder
	{
		public:
			Folder(){}
			Folder(const Folder& fd);
			Folder& operator=(const Folder& fd);
			~Folder();

	//		void save(const Message&);
	//		void remove(const Message&);

			void addMsg(const Message*);
			void remMsg(const Message*);
		private:
			set<Message*> messages;
			void put_folder_to_message(const Folder&);
			void remove_folder_from_message();
	};
}

#endif
