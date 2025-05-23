/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:22:05 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/24 16:27:17 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename C>
const int& easyfind(const C& container, const int element)
{
    typename C::const_iterator it;

    if (container.empty())
        throw std::exception();
    it = std::find(container.begin(), container.end(), element);
    if (it != container.end()){
        return *it;
    }
    else
        throw std::exception();
}