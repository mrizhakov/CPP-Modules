/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/23 23:05:42 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <deque>


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>  {
    
    public:
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
    MutantStack &operator=(const MutantStack &other) {
        if (this != &other)
            std::stack<T, Container>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    
    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }
    const_iterator begin() const {
        return this->c.begin();
    }
    const_iterator end() const {
        return this->c.end();
    }
};