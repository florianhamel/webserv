/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgiHandler.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:33:01 by viroques          #+#    #+#             */
/*   Updated: 2022/02/09 11:10:50 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGI_HANDLER_H
# define CGI_HANDLER_H

# include "RequestParser.hpp"
# include <unistd.h>
# include "utils.hpp"

// Open include
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

// fileno inclde
# include <stdio.h>

class cgiHandler
{
private:

    std::map<std::string, std::string>  _env;
    std::string                         _body;

public:

    cgiHandler();
    ~cgiHandler();
    cgiHandler(Request &req);
    cgiHandler(const cgiHandler &cgi);
    cgiHandler&     operator=(const cgiHandler &cgi);

    char            **envToString();
    char            **keyMapConvert(std::string key);
    std::string     execute(std::string pathToBinaryCgi);
};

#endif
