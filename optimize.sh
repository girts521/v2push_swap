#!/bin/bash

#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <file_with_operations>"
    exit 1
fi

input_file="$1"
temp_file=$(mktemp)

# Read file into an array
mapfile -t ops < "$input_file"

optimized_ops=()

for ((i = 0; i < ${#ops[@]}; i++)); do
    if [[ ${#optimized_ops[@]} -gt 0 ]]; then
        last="${optimized_ops[-1]}"
    else
        last=""
    fi

    current="${ops[i]}"
    next="${ops[i+1]:-}"
    next2="${ops[i+2]:-}"

    # Remove direct reversals (pb -> pa, ra -> rra, etc.)
    case "$last:$current" in
        "pb:pa"|"pa:pb"|"ra:rra"|"rra:ra"|"rb:rrb"|"rrb:rb"|"rr:rrr"|"rrr:rr")
            unset 'optimized_ops[-1]'
            continue
            ;;
    esac

    # Optimize specific sequences
    case "$current:$next" in
        "ra:rb"|"rb:ra")
            optimized_ops+=("rr")
            ((i++))
            continue
            ;;
        "rra:rrb"|"rrb:rra")
            optimized_ops+=("rrr")
            ((i++))
            continue
            ;;
    esac

    case "$current:$next:$next2" in
        "ra:pb:rra")
            optimized_ops+=("sa" "pb")
            ((i+=2))
            continue
            ;;
        "rb:pa:rrb")
            optimized_ops+=("sb" "pa")
            ((i+=2))
            continue
            ;;
    esac

    optimized_ops+=("$current")
done

# Write optimized output
printf "%s\n" "${optimized_ops[@]}" > "$temp_file"
mv "$temp_file" "$input_file"
echo "Optimization complete. Updated file: $input_file"

