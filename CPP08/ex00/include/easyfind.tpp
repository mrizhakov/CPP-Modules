/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:22:05 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/14 18:26:58 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename C, typename T>
const T& easyfind(const C& container, const T& element)
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