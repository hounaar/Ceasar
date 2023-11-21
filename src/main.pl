#!/usr/bin/perl
use strict;
use warnings;

use File::Slurp;
use PDF::API2;

# Function to decode the input string using Caesar cipher
sub decode {
    my ($input, $shift) = @_;
    my @decoded_content;
    foreach my $char (split //, $input) {
        if ($char =~ /[a-zA-Z]/) {
            my $base = $char =~ /[a-z]/ ? ord('a') : ord('A');
            my $decoded_char = chr(((ord($char) - $base - $shift) % 26) + $base);
            push @decoded_content, $decoded_char;
        } else {
            push @decoded_content, $char;
        }
    }
    return join('', @decoded_content);
}

# Function to encode the input string using Caesar cipher
sub encode {
    my ($input, $shift) = @_;
    my @encoded_content;
    foreach my $char (split //, $input) {
        if ($char =~ /[a-zA-Z]/) {
            my $base = $char =~ /[a-z]/ ? ord('a') : ord('A');
            my $encoded_char = chr(((ord($char) - $base + $shift) % 26) + $base);
            push @encoded_content, $encoded_char;
        } else {
            push @encoded_content, $char;
        }
    }
    return join('', @encoded_content);
}

# Function to save content to a file
sub save_to_file {
    my ($content, $filename) = @_;
    open my $fh, '>', $filename or die "Error: Unable to create or write to the file $filename: $!";
    print $fh $content;
    close $fh;
}

if (@ARGV < 2) {
    print "Usage: $0 <options> <input_file>\n";
    print "Options:\n";
    print "  -h: Help\n";
    print "  -e: Encode the file\n";
    print "  -d: Decode the file\n";
    print "  -ep: Encode and print\n";
    print "  -ed: Decode and print\n";
    print "  -epdf: Encode and save as PDF\n";
    print "  -dpdf: Decode and save as PDF\n";
    exit(1);
}

my $option = shift @ARGV;

if ($option eq "-h") {
    print "Help: Display help and usage information.\n";
} elsif ($option =~ /^-(e|d|ep|ed|epdf|dpdf)$/) {
    if (@ARGV < 1) {
        print "Error: Missing input file or shift value.\n";
        exit(1);
    }
    my $shift = shift @ARGV;
    my $input_filename = shift @ARGV;
    my $file_content = read_file($input_filename);

    if ($option eq "-e" || $option eq "-ep" || $option eq "-epdf") {
        my $encoded_content = encode($file_content, $shift);

        if ($option eq "-ep") {
            print $encoded_content;
        } elsif ($option eq "-epdf") {
            # Implement PDF generation for encoded content (not shown in this example)
            print "PDF generation for encoded content is not implemented.\n";
        } else {
            save_to_file($encoded_content, $input_filename);
        }
    } elsif ($option eq "-d" || $option eq "-ed" || $option eq "-dpdf") {
        my $decoded_content = decode($file_content, $shift);

        if ($option eq "-ed") {
            print $decoded_content;
        } elsif ($option eq "-dpdf") {
            # Implement PDF generation for decoded content (not shown in this example)
            print "PDF generation for decoded content is not implemented.\n";
        } else {
            save_to_file($decoded_content, $input_filename);
        }
    }
} else {
    print "Error: Invalid option.\n";
    exit(1);
}
