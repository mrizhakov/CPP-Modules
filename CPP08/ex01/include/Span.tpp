/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:08:32 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/18 17:17:29 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
template <typename Iterator>
void        Span::addRange(Iterator begin, Iterator end) {
    size_t distance = std::distance(begin, end);
    if (this->current_stored + distance > this->max_stored)
        throw std::exception();
    this->vec.insert(this->vec.end(), begin, end);
    this->current_stored += distance;
}