/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:23:39 by klew              #+#    #+#             */
/*   Updated: 2023/03/11 16:23:43 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain {
 private:
	std::string ideas[100];
 public:
	Brain(void);
	Brain(const Brain& obj);
	Brain& operator=(const Brain& obj);
	~Brain(void);
	std::string getIdeas(int n) const;
	void setIdeas(std::string idea, int n);
};

#endif