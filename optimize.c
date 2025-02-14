/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:28:25 by girts             #+#    #+#             */
/*   Updated: 2025/02/12 16:05:37 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
// merges operations
// 	RA PB RRA -> SA PB
// 	RB PA RRB -> SB PA
// void merge_op(t_instructions **instructions)
// {
//     t_instructions *current_node;
//     t_instructions *after;
//     t_instructions *new_node;

//     current_node = *instructions;
//     while(current_node)
//     {
//         if (ft_strncmp(current_node->value, "ra", ft_strlen(current_node->value)) == 0 && ft_strncmp(current_node->next->value, "pb", ft_strlen(current_node->next->value)) == 0 && ft_strncmp(current_node->next->next->value, "rra", ft_strlen(current_node->next->next->value)) == 0)
//         {
//             //SA PB
//             after = current_node->prev;
//             remove_node(instructions, current_node->next->next);
//             remove_node(instructions, current_node->next);
//             remove_node(instructions, current_node);
//             new_node = create_new_node("sa");
//             add_after(instructions, new_node, after);
//             after = new_node;
//             new_node = create_new_node("pb");
//             add_after(instructions, new_node, after);
//             current_node = new_node;
//         }
//         else if  (ft_strncmp(current_node->value, "rb", ft_strlen(current_node->value)) == 0 && ft_strncmp(current_node->next->value, "pa", ft_strlen(current_node->next->value)) == 0 && ft_strncmp(current_node->next->next->value, "rrb", ft_strlen(current_node->next->next->value)) == 0)
//         {
//             // SB PA
//             after = current_node->prev;
//             remove_node(instructions, current_node->next->next);
//             remove_node(instructions, current_node->next);
//             remove_node(instructions, current_node);
//             new_node = create_new_node("sb");
//             add_after(instructions, new_node, after);
//             after = new_node;
//             new_node = create_new_node("pa");
//             add_after(instructions, new_node, after);
//             current_node = new_node;
//         }
//         current_node = current_node->next;
//     }
    
// }

void merge_op(t_instructions **instructions)
{
    t_instructions *current_node;
    t_instructions *after;
    t_instructions *new_node;

    current_node = *instructions;
    while (current_node && current_node->next && current_node->next->next)
    {
        if (ft_strncmp(current_node->value, "ra", ft_strlen("ra")) == 0 && 
            ft_strncmp(current_node->next->value, "pb", ft_strlen("pb")) == 0 && 
            ft_strncmp(current_node->next->next->value, "rra", ft_strlen("rra")) == 0)
        {
            // Replace RA PB RRA with SA PB
            after = current_node->prev;
            remove_node(instructions, current_node->next->next); // Remove RRA
            remove_node(instructions, current_node->next);      // Remove PB
            remove_node(instructions, current_node);            // Remove RA
            new_node = create_new_node("sa");
            add_after(instructions, new_node, after);           // Add SA
            after = new_node;
            new_node = create_new_node("pb");
            add_after(instructions, new_node, after);            // Add PB
            current_node = new_node->next; // Continue from the node after PB
            ft_printf("merged\n");
        }
        else if (ft_strncmp(current_node->value, "rb", ft_strlen("rb")) == 0 && 
                 ft_strncmp(current_node->next->value, "pa", ft_strlen("pa")) == 0 && 
                 ft_strncmp(current_node->next->next->value, "rrb", ft_strlen("rrb")) == 0)
        {
            // Replace RB PA RRB with SB PA
            after = current_node->prev;
            remove_node(instructions, current_node->next->next); // Remove RRB
            remove_node(instructions, current_node->next);      // Remove PA
            remove_node(instructions, current_node);            // Remove RB
            new_node = create_new_node("sb");
            add_after(instructions, new_node, after);           // Add SB
            after = new_node;
            new_node = create_new_node("pa");
            add_after(instructions, new_node, after);           // Add PA
            current_node = new_node->next; // Continue from the node after PA
            ft_printf("merged\n");
        }
        else
        {
            current_node = current_node->next; // No merge, move to the next node
        }
    }
}


// void merge_op(t_instructions **instructions)
// {
//     t_instructions *current_node;
//     t_instructions *after;
//     t_instructions *new_node;

//     current_node = *instructions;
//     while(current_node && current_node->next && current_node->next->next)
//     {
//         if (ft_strncmp(current_node->value, "ra", ft_strlen(current_node->value)) == 0 && 
//             ft_strncmp(current_node->next->value, "pb", ft_strlen(current_node->next->value)) == 0 && 
//             ft_strncmp(current_node->next->next->value, "rra", ft_strlen(current_node->next->next->value)) == 0)
//         {
//             //SA PB
//             after = current_node->prev;
//             remove_node(instructions, current_node->next->next);
//             remove_node(instructions, current_node->next);
//             remove_node(instructions, current_node);
//             new_node = create_new_node("sa");
//             add_after(instructions, new_node, after);
//             after = new_node;
//             new_node = create_new_node("pb");
//             add_after(instructions, new_node, after);
//             current_node = new_node;
//         }
//         else if (ft_strncmp(current_node->value, "rb", ft_strlen(current_node->value)) == 0 && 
//                  ft_strncmp(current_node->next->value, "pa", ft_strlen(current_node->next->value)) == 0 && 
//                  ft_strncmp(current_node->next->next->value, "rrb", ft_strlen(current_node->next->next->value)) == 0)
//         {
//             // SB PA
//             after = current_node->prev;
//             remove_node(instructions, current_node->next->next);
//             remove_node(instructions, current_node->next);
//             remove_node(instructions, current_node);
//             new_node = create_new_node("sb");
//             add_after(instructions, new_node, after);
//             after = new_node;
//             new_node = create_new_node("pa");
//             add_after(instructions, new_node, after);
//             current_node = new_node;
//         }
//         current_node = current_node->next;
//     }
// }

// merges operations
// SA SB or SB SA -> SS
// RA RB or RB RA -> RR
// RRA RRB or RRB RRA -> RRR



// removes PA PB or PB PA


void optimize(t_instructions **instructions)
{
    merge_op(instructions);
}