# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Signing;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

}

########################################################################
package Signing::MsgCertificateChainDep;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{root_certificate} = ();
    my $n_root_certificate = 20;
    for (my $i = 0; $i < $n_root_certificate; $i++) {
        push @{$self->{root_certificate}}, $self->{_io}->read_u1();
    }
    $self->{intermediate_certificate} = ();
    my $n_intermediate_certificate = 20;
    for (my $i = 0; $i < $n_intermediate_certificate; $i++) {
        push @{$self->{intermediate_certificate}}, $self->{_io}->read_u1();
    }
    $self->{corrections_certificate} = ();
    my $n_corrections_certificate = 20;
    for (my $i = 0; $i < $n_corrections_certificate; $i++) {
        push @{$self->{corrections_certificate}}, $self->{_io}->read_u1();
    }
    $self->{expiration} = Signing::UtcTime->new($self->{_io}, $self, $self->{_root});
    $self->{signature} = ();
    my $n_signature = 64;
    for (my $i = 0; $i < $n_signature; $i++) {
        push @{$self->{signature}}, $self->{_io}->read_u1();
    }
}

sub root_certificate {
    my ($self) = @_;
    return $self->{root_certificate};
}

sub intermediate_certificate {
    my ($self) = @_;
    return $self->{intermediate_certificate};
}

sub corrections_certificate {
    my ($self) = @_;
    return $self->{corrections_certificate};
}

sub expiration {
    my ($self) = @_;
    return $self->{expiration};
}

sub signature {
    my ($self) = @_;
    return $self->{signature};
}

########################################################################
package Signing::MsgEd25519SignatureDepB;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{stream_counter} = $self->{_io}->read_u1();
    $self->{on_demand_counter} = $self->{_io}->read_u1();
    $self->{signature} = ();
    my $n_signature = 64;
    for (my $i = 0; $i < $n_signature; $i++) {
        push @{$self->{signature}}, $self->{_io}->read_u1();
    }
    $self->{fingerprint} = ();
    my $n_fingerprint = 20;
    for (my $i = 0; $i < $n_fingerprint; $i++) {
        push @{$self->{fingerprint}}, $self->{_io}->read_u1();
    }
    $self->{signed_messages} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{signed_messages}}, $self->{_io}->read_u4le();
    }
}

sub stream_counter {
    my ($self) = @_;
    return $self->{stream_counter};
}

sub on_demand_counter {
    my ($self) = @_;
    return $self->{on_demand_counter};
}

sub signature {
    my ($self) = @_;
    return $self->{signature};
}

sub fingerprint {
    my ($self) = @_;
    return $self->{fingerprint};
}

sub signed_messages {
    my ($self) = @_;
    return $self->{signed_messages};
}

########################################################################
package Signing::MsgEd25519CertificateDep;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{n_msg} = $self->{_io}->read_u1();
    $self->{fingerprint} = ();
    my $n_fingerprint = 20;
    for (my $i = 0; $i < $n_fingerprint; $i++) {
        push @{$self->{fingerprint}}, $self->{_io}->read_u1();
    }
    $self->{certificate_bytes} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{certificate_bytes}}, $self->{_io}->read_u1();
    }
}

sub n_msg {
    my ($self) = @_;
    return $self->{n_msg};
}

sub fingerprint {
    my ($self) = @_;
    return $self->{fingerprint};
}

sub certificate_bytes {
    my ($self) = @_;
    return $self->{certificate_bytes};
}

########################################################################
package Signing::UtcTime;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{year} = $self->{_io}->read_u2le();
    $self->{month} = $self->{_io}->read_u1();
    $self->{day} = $self->{_io}->read_u1();
    $self->{hours} = $self->{_io}->read_u1();
    $self->{minutes} = $self->{_io}->read_u1();
    $self->{seconds} = $self->{_io}->read_u1();
    $self->{ns} = $self->{_io}->read_u4le();
}

sub year {
    my ($self) = @_;
    return $self->{year};
}

sub month {
    my ($self) = @_;
    return $self->{month};
}

sub day {
    my ($self) = @_;
    return $self->{day};
}

sub hours {
    my ($self) = @_;
    return $self->{hours};
}

sub minutes {
    my ($self) = @_;
    return $self->{minutes};
}

sub seconds {
    my ($self) = @_;
    return $self->{seconds};
}

sub ns {
    my ($self) = @_;
    return $self->{ns};
}

########################################################################
package Signing::EcdsaSignature;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{len} = $self->{_io}->read_u1();
    $self->{data} = ();
    my $n_data = 72;
    for (my $i = 0; $i < $n_data; $i++) {
        push @{$self->{data}}, $self->{_io}->read_u1();
    }
}

sub len {
    my ($self) = @_;
    return $self->{len};
}

sub data {
    my ($self) = @_;
    return $self->{data};
}

########################################################################
package Signing::MsgEd25519SignatureDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{signature} = ();
    my $n_signature = 64;
    for (my $i = 0; $i < $n_signature; $i++) {
        push @{$self->{signature}}, $self->{_io}->read_u1();
    }
    $self->{fingerprint} = ();
    my $n_fingerprint = 20;
    for (my $i = 0; $i < $n_fingerprint; $i++) {
        push @{$self->{fingerprint}}, $self->{_io}->read_u1();
    }
    $self->{signed_messages} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{signed_messages}}, $self->{_io}->read_u4le();
    }
}

sub signature {
    my ($self) = @_;
    return $self->{signature};
}

sub fingerprint {
    my ($self) = @_;
    return $self->{fingerprint};
}

sub signed_messages {
    my ($self) = @_;
    return $self->{signed_messages};
}

########################################################################
package Signing::MsgCertificateChain;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{root_certificate} = ();
    my $n_root_certificate = 20;
    for (my $i = 0; $i < $n_root_certificate; $i++) {
        push @{$self->{root_certificate}}, $self->{_io}->read_u1();
    }
    $self->{intermediate_certificate} = ();
    my $n_intermediate_certificate = 20;
    for (my $i = 0; $i < $n_intermediate_certificate; $i++) {
        push @{$self->{intermediate_certificate}}, $self->{_io}->read_u1();
    }
    $self->{corrections_certificate} = ();
    my $n_corrections_certificate = 20;
    for (my $i = 0; $i < $n_corrections_certificate; $i++) {
        push @{$self->{corrections_certificate}}, $self->{_io}->read_u1();
    }
    $self->{expiration} = Signing::UtcTime->new($self->{_io}, $self, $self->{_root});
    $self->{signature} = Signing::EcdsaSignature->new($self->{_io}, $self, $self->{_root});
}

sub root_certificate {
    my ($self) = @_;
    return $self->{root_certificate};
}

sub intermediate_certificate {
    my ($self) = @_;
    return $self->{intermediate_certificate};
}

sub corrections_certificate {
    my ($self) = @_;
    return $self->{corrections_certificate};
}

sub expiration {
    my ($self) = @_;
    return $self->{expiration};
}

sub signature {
    my ($self) = @_;
    return $self->{signature};
}

########################################################################
package Signing::MsgEcdsaCertificate;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{n_msg} = $self->{_io}->read_u1();
    $self->{certificate_id} = ();
    my $n_certificate_id = 4;
    for (my $i = 0; $i < $n_certificate_id; $i++) {
        push @{$self->{certificate_id}}, $self->{_io}->read_u1();
    }
    $self->{flags} = $self->{_io}->read_u1();
    $self->{certificate_bytes} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{certificate_bytes}}, $self->{_io}->read_u1();
    }
}

sub n_msg {
    my ($self) = @_;
    return $self->{n_msg};
}

sub certificate_id {
    my ($self) = @_;
    return $self->{certificate_id};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub certificate_bytes {
    my ($self) = @_;
    return $self->{certificate_bytes};
}

########################################################################
package Signing::MsgEcdsaSignatureDepB;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{flags} = $self->{_io}->read_u1();
    $self->{stream_counter} = $self->{_io}->read_u1();
    $self->{on_demand_counter} = $self->{_io}->read_u1();
    $self->{certificate_id} = ();
    my $n_certificate_id = 4;
    for (my $i = 0; $i < $n_certificate_id; $i++) {
        push @{$self->{certificate_id}}, $self->{_io}->read_u1();
    }
    $self->{n_signature_bytes} = $self->{_io}->read_u1();
    $self->{signature} = ();
    my $n_signature = 72;
    for (my $i = 0; $i < $n_signature; $i++) {
        push @{$self->{signature}}, $self->{_io}->read_u1();
    }
    $self->{signed_messages} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{signed_messages}}, $self->{_io}->read_u1();
    }
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub stream_counter {
    my ($self) = @_;
    return $self->{stream_counter};
}

sub on_demand_counter {
    my ($self) = @_;
    return $self->{on_demand_counter};
}

sub certificate_id {
    my ($self) = @_;
    return $self->{certificate_id};
}

sub n_signature_bytes {
    my ($self) = @_;
    return $self->{n_signature_bytes};
}

sub signature {
    my ($self) = @_;
    return $self->{signature};
}

sub signed_messages {
    my ($self) = @_;
    return $self->{signed_messages};
}

########################################################################
package Signing::MsgEcdsaSignature;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{flags} = $self->{_io}->read_u1();
    $self->{stream_counter} = $self->{_io}->read_u1();
    $self->{on_demand_counter} = $self->{_io}->read_u1();
    $self->{certificate_id} = ();
    my $n_certificate_id = 4;
    for (my $i = 0; $i < $n_certificate_id; $i++) {
        push @{$self->{certificate_id}}, $self->{_io}->read_u1();
    }
    $self->{signature} = Signing::EcdsaSignature->new($self->{_io}, $self, $self->{_root});
    $self->{signed_messages} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{signed_messages}}, $self->{_io}->read_u1();
    }
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub stream_counter {
    my ($self) = @_;
    return $self->{stream_counter};
}

sub on_demand_counter {
    my ($self) = @_;
    return $self->{on_demand_counter};
}

sub certificate_id {
    my ($self) = @_;
    return $self->{certificate_id};
}

sub signature {
    my ($self) = @_;
    return $self->{signature};
}

sub signed_messages {
    my ($self) = @_;
    return $self->{signed_messages};
}

########################################################################
package Signing::MsgEcdsaSignatureDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{flags} = $self->{_io}->read_u1();
    $self->{stream_counter} = $self->{_io}->read_u1();
    $self->{on_demand_counter} = $self->{_io}->read_u1();
    $self->{certificate_id} = ();
    my $n_certificate_id = 4;
    for (my $i = 0; $i < $n_certificate_id; $i++) {
        push @{$self->{certificate_id}}, $self->{_io}->read_u1();
    }
    $self->{signature} = ();
    my $n_signature = 64;
    for (my $i = 0; $i < $n_signature; $i++) {
        push @{$self->{signature}}, $self->{_io}->read_u1();
    }
    $self->{signed_messages} = ();
    while (!$self->{_io}->is_eof()) {
        push @{$self->{signed_messages}}, $self->{_io}->read_u1();
    }
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub stream_counter {
    my ($self) = @_;
    return $self->{stream_counter};
}

sub on_demand_counter {
    my ($self) = @_;
    return $self->{on_demand_counter};
}

sub certificate_id {
    my ($self) = @_;
    return $self->{certificate_id};
}

sub signature {
    my ($self) = @_;
    return $self->{signature};
}

sub signed_messages {
    my ($self) = @_;
    return $self->{signed_messages};
}

1;
