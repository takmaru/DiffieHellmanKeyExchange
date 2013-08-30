#pragma once

#include <wincrypt.h>
#include "DHBlob.h"

namespace DHKEx {

class CDHKeyMaker {
public:
	CDHKeyMaker();
	~CDHKeyMaker();

public:
	DHBlob createPublicKey() const;
	DHBlob createPublicKey(const DHBlob& prime, const DHBlob& generator) const;
	DHBlob prime() const;
	DHBlob generator() const;
	HCRYPTKEY createSecretKey(const DHBlob& publicKey);

private:
	HCRYPTPROV m_DHCryptoProvider;
};

}
