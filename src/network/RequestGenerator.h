#ifndef REQUESTGENERATOR_H
#define REQUESTGENERATOR_H
#include <QString>
#include <memory>

class QSettings;

namespace compilerExplorer {
namespace network{
class Request;
class RequestGeneratorPrivate;
class RequestGenerator
{
public:
	RequestGenerator();
	RequestGenerator(const QString &address, const int port);
	virtual ~RequestGenerator();
	Request *createCompilerRequest();
	QString address() const;
	void setAddress(const QString &address);
	int port() const;
	void setPort(const int port);
	void setCompilerLocation(const QString &location);
	void setCompilerOptions(const QString &options);
	void setSourceCode(const QString &code);
	void setFilters(const QStringList &filters);
	void updateSettings(const QSettings &settings);
	static std::unique_ptr<Request> comilersListRequest(const QString &address, const int port);
private:
	std::unique_ptr<RequestGeneratorPrivate> d;
};
}
}
#endif // REQUESTGENERATOR_H
