/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SockClient.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:39:50 by fhamel            #+#    #+#             */
/*   Updated: 2022/02/16 14:57:54 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCK_CLIENT_HPP
# define SOCK_CLIENT_HPP

# include <string>
# include <vector>
# include <sstream>
# include <iostream>

# include "RequestParser.hpp"
# include "ResponseHeader.hpp"

class SockClient {

	private:

		char			*ip_;
		size_t			port_;
		bool			chunk_;
		std::string		tmpRequest_;
		std::string		finalRequest_;
		Request			request_;
		ResponseHeader	responseHeader_;
		std::string		responseBody_;
		int				fd_[2];

	public:
		SockClient(void);
		SockClient(const SockClient &sockClient);
		~SockClient(void);
		SockClient	&operator=(const SockClient &sockClient);

		/* setters */
		void			setIp(char *ip);
		void			setPort(size_t port);
		void			setChunk(bool chunk);
		void			setRequest(const Request &request);
		void			setResponseHeader(const ResponseHeader &responseHeader);
		/* checkers */
		bool			isChunk(void) const;
		bool			isTmpRequestChunk(void) const;
		bool			isChunkEof(void) const;
		bool			isDeleteRequest(void) const;
		bool			isBadRequest(void) const;
		/* getters */
		char			*getIp(void) const;
		size_t			getPort(void) const;
		std::string		&getTmpRequest(void);
		std::string		&getFinalRequest(void);
		Request			&getRequest(void);
		ResponseHeader	&getResponseHeader(void);
		std::string		&getResponseBody(void);
		int				&getEndPipe(void);
		int				&getBeginPipe(void);

};

#endif
