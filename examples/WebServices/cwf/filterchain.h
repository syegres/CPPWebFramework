/**
  @file filterchain.h
  @author Herik Lima
*/

#ifndef FILTERCHAIN_H
#define FILTERCHAIN_H

#include "filemanager.h"
#include "httpservletrequest.h"
#include "httpservletresponse.h"
#include "httpservlet.h"
#include "filterchain.h"
#include "httpparser.h"
#include "httprequestmethod.h"
#include "requestdispatcher.h"
#include <QFile>

namespace CWF
{
    /**
     * @brief The FilterChain class is responsable to dispatch a requisition.
     * This class was built to work with Filter. Always when a Filter makes all the
     * necessary validations, it can dispatches the requisition to the FilterChain.
     * NOTE: It is a final class, you can't derive from it.
     */
    class FilterChain final
    {
        HttpServlet      *servlet = nullptr;
        /**
         * @brief This method writes a response into the HttpServletResponse.
         * @param response : This is a reference to the HttpServletResponse.
         * @param path     : This is a reference to the QString.
         * @param url      : This is a reference to the QString.
         * @param name     : This is a reference to the QByteArray.
         * @param value    : This is a reference to the QByteArray.
         */
        void write(HttpServletResponse &response, const QString &path, const QString &url, const QByteArray &name, const QByteArray &value) const;
    public:
        /**
         * @brief FilterChain
         * @param servlet
         */
        FilterChain(HttpServlet *servlet);
        /**
         * @brief This method dispaches a requisition to a HttpServletRequest or, if the requesition
         * is for a file, it can reads and send the file through the HttpServletResponse.
         * @param request  : This is a reference to the HttpServletRequest.
         * @param response : This is a reference to the HttpServletResponse.
         */
        void doFilter(CWF::HttpServletRequest &request, CWF::HttpServletResponse &response);
    };
}

#endif // FILTERCHAIN_H
