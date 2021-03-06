/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SockClient.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:39:50 by fhamel            #+#    #+#             */
/*   Updated: 2022/02/15 15:17:21 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCK_CLIENT_HPP
# define SOCK_CLIENT_HPP

# include <string>
# include <vector>
# include <sstream>

class SockClient {
	
	private:
		char		*ip_;
		size_t		port_;
		std::string	tmpRequest_;
		std::string	request_;
//		int			fd_[2];
		bool		chunk_;

	public:
		SockClient(void);
		SockClient(const SockClient &sockClient);
		~SockClient(void);
		SockClient	&operator=(const SockClient &sockClient);

		/* setters */
		void		setIp(char *ip);
		void		setPort(size_t port);
		void		setChunk(bool chunk);
		/* checkers */
		bool		isChunk(void) const;
		bool		isTmpRequestChunk(void) const;
		bool		isChunkEof(void) const;
		bool		isDeleteRequest(void) const;
		bool		isBadRequest(void) const;
		/* getters */
		char		*getIp(void) const;
		size_t		getPort(void) const;
		std::string	&getTmpRequest(void);
		std::string	&getRequest(void);
};

#endif
