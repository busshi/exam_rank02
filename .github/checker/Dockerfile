# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 11:02:19 by aldubar           #+#    #+#              #
#    Updated: 2021/07/18 11:03:22 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		ubuntu:latest

RUN		apt update && apt install -y clang make

COPY		* /.github/checker

WORKDIR		/.github/checker

ENTRYPOINT	[ "make", "check" ]
