#include "stdafx.h"
#include "DHKeyMaker.h"

#include <MyLib/Crypto/CryptoProvider.h>
#include <MyLib/Crypto/CryptoKey.h>
#include "DHKExException.h"


DHKEx::CDHKeyMaker::CDHKeyMaker() : m_DHCryptoProvider(NULL) {
}
DHKEx::CDHKeyMaker::~CDHKeyMaker() {
}

DHKEx::DHBlob DHKEx::CDHKeyMaker::createPublicKey() const {

	// Microsoft Diffie-Hellman Crypto Provider を取得
	MyLib::Crypto::CCryptoProvider cryptoProvider;
	if(!::CryptAcquireContext(cryptoProvider, NULL, MS_ENH_DSS_DH_PROV, PROV_DSS_DH, CRYPT_VERIFYCONTEXT)) {
		RAISE_DHKExEXCEPTION("createPublicKey CryptAcquireContext err(%u)", ::GetLastError());
    }

	// 一時的な秘密キーを生成（Prime、Generatorは自動生成）
	MyLib::Crypto::CCryptoKey cryptoKey;
	if(!::CryptGenKey(cryptoProvider, CALG_DH_EPHEM, CRYPT_EXPORTABLE, cryptoKey)) {
		RAISE_DHKExEXCEPTION("createPublicKey CryptGenKey err(%u)", ::GetLastError());
	}

/*
    // Public key value, (G^X) mod P is calculated.
    DWORD dwDataLen1;

    // Get the size for the key BLOB.
    fReturn = CryptExportKey(
        hPrivateKey1,
        NULL,
        PUBLICKEYBLOB,
        0,
        NULL,
        &dwDataLen1);
    if(!fReturn)
    {
        goto ErrorExit;
    }

    // Allocate the memory for the key BLOB.
    if(!(pbKeyBlob1 = (PBYTE)malloc(dwDataLen1)))
    { 
        goto ErrorExit;
    }

    // Get the key BLOB.
    fReturn = CryptExportKey(
        hPrivateKey1,
        0,
        PUBLICKEYBLOB,
        0,
        pbKeyBlob1,
        &dwDataLen1);
    if(!fReturn)
    {
        goto ErrorExit;
    }
*/
	return DHKEx::DHBlob();
}
DHKEx::DHBlob DHKEx::CDHKeyMaker::createPublicKey(const DHBlob& prime, const DHBlob& generator) const {
	return DHKEx::DHBlob();
}
DHKEx::DHBlob DHKEx::CDHKeyMaker::prime() const {
	return DHKEx::DHBlob();
}
DHKEx::DHBlob DHKEx::CDHKeyMaker::generator() const {
	return DHKEx::DHBlob();
}
HCRYPTKEY DHKEx::CDHKeyMaker::createSecretKey(const DHBlob& publicKey) {
	return NULL;
}
