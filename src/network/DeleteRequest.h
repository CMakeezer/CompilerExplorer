#ifndef DELETEREQUEST_H
#define DELETEREQUEST_H
#include "GetRequest.h"
#include "compilerexplorer_global.h"

namespace compilerExplorer {
namespace network{
class COMPILEREXPLORERSHARED_EXPORT DeleteRequest : public GetRequest
{
public:
	DeleteRequest();
};
}
}
#endif // DELETEREQUEST_H
