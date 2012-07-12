#ifndef __DBMANAGER_H__
#define __DBMANAGER_H__

class CDbManager {

	static CDbManager* ms_instance;

public:
	static CDbManager* Instance();
	static void Release();

private:
	CDbManager();
	virtual ~CDbManager();

};

#endif // __DBMANAGER_H__
