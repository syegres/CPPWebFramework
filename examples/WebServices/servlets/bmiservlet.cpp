#include "bmiservlet.h"

void BmiServlet::doGet(CWF::HttpServletRequest &request, CWF::HttpServletResponse &response)
{
    QJsonObject json;
    User user;

    request.fillQObject(&user);

    json["bmi"]      =  user.getBmi();
    json["name"]     =  user.getName();
    json["category"] =  user.getCategory();
    json["mass"]     =  user.getMass();
    json["height"]   =  user.getHeight();


    response.addHeader("Content-Type", "application/json");
    response.write(QJsonDocument(json).toJson());
    //Call
    //http://127.0.0.1:8080/bmi?name=Herik&mass=75&height=1.75
}
