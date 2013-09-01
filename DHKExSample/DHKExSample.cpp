// DHKExSample.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include <MyLib/String/StringUtil.h>
#include "DHKeyServer.h"
#include "DHKeyClient.h"

int _tmain(int argc, _TCHAR* argv[]) {
	CDHKeyServer dhkeyServer;
	dhkeyServer.createPublickey();
	CDHKeyClient dhkeyClient;
	dhkeyClient.createPublickey(dhkeyServer.prime(), dhkeyServer.generator());
	dhkeyServer.setClientKey(dhkeyClient.publicKey());
	dhkeyClient.setServerKey(dhkeyServer.publicKey());

	std::tcout <<
		_T("[Sever Public Key] size=") << dhkeyServer.publicKey().size() << _T("byte") << std::endl << 
		MyLib::String::toHexStr(&dhkeyServer.publicKey()[0], dhkeyServer.publicKey().size()) << std::endl <<
		_T("[Prime] size=") << dhkeyServer.prime().size() << _T("byte") << std::endl <<
		MyLib::String::toHexStr(&dhkeyServer.prime()[0], dhkeyServer.prime().size()) << std::endl <<
		_T("[Generator] size=") << dhkeyServer.generator().size() << _T("byte") << std::endl <<
		MyLib::String::toHexStr(&dhkeyServer.generator()[0], dhkeyServer.generator().size()) << std::endl <<
		_T("[Client Public Key] size=") << dhkeyClient.publicKey().size() << _T("byte") << std::endl << 
		MyLib::String::toHexStr(&dhkeyClient.publicKey()[0], dhkeyClient.publicKey().size()) << std::endl;
	return 0;
}

