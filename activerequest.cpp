#include "activerequest.h"

//#include <QQmlEngine>

//AbstractActiveRequest *AbstractActiveRequestTarget::cppOwned(AbstractActiveRequest *request) const
//{
//    QQmlEngine::setObjectOwnership(request, QQmlEngine::JavaScriptOwnership);
//}


AbstractActiveRequestTarget::AbstractActiveRequestTarget(QObject *parent)
    : QObject(parent)
{

}
