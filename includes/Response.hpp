/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:33:08 by viroques          #+#    #+#             */
/*   Updated: 2022/02/08 23:54:16 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_H
#define RESPONSE_H

# include <iostream>
# include <fstream>
# include <sstream>

# include <map>

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# include "ResponseHeader.hpp"  
# include "RequestParser.hpp"
# include "cgiHandler.hpp"
# include "Server.hpp"
# include "autoIndex.hpp"
# include "utils.hpp"

class Response {

public:

    Response();
    Response(Server &serv);
    Response(const Response &res);
    ~Response();
    Response    &operator=(const Response &res);

    /* Init Function for make Response */
    int             initRequest(Request &req);
    void            setLocationConf();
    void            makeAnswer(Request &req);

    /* Reading/send Data */
    int             readErrorPage(std::string &path);
    void            readContent(std::string &path);
    void            sendPage(int code);

    /* HTTP Methods */
    void            getMethod();
    void            headMethod();
    void            postMethod();
    void            deleteMethod();
    
    /* Helper Functions */
    int             upload();
    bool            isAllow(std::string method);
	std::string		autoIndexBuilder(std::string path);

    /* Getters */

    Request&        getRequest();
    std::string&    getPath();
    std::string&    getBody();
    std::string&    getResponse();
    Server&         getServ();
    map_str&        getErrorPage();
    std::string&    getPathCgi();
    std::string&    getExtensionCgi();
    std::string&    getIndex();
    std::string&    getRoot();
    std::string&    getGeneralRoot();
    bool            getAutoIndex();
    vec_str&        getAllowMethods();
    std::string&    getUploadDest();
    ResponseHeader& getHeader();
    std::string&    getLocation();

private:

    Request                     _request;
    std::string                 _path;
    std::string                 _body;
    std::string                 _response;
    Server                      _serv;
    map_str                     _errorPage;
    std::string                 _pathCgi;
    std::string                 _extensionCgi;
    std::string                 _index;
    std::string                 _root;
    std::string                 _generalRoot;
    bool                        _AutoIndex;
    vec_str                     _allowMethods;
    std::string                 _uploadDest;
    ResponseHeader              _header;
    std::string                 _location;

    std::map<std::string, void (Response::*)()> _methods;  
};

#endif
