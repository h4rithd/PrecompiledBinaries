# PrecompiledBinaries

![Repository](https://img.shields.io/badge/repo-precompiled--binaries-blue)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey)
![Use](https://img.shields.io/badge/use-authorized%20security%20testing-red)

A curated collection of precompiled binaries commonly used during authorized penetration testing, red team operations, lab research, exploit validation, Active Directory assessment, privilege-escalation testing, tunneling, pivoting, and security tooling workflows.

This repository is intended to save time when a tool is needed quickly in a controlled assessment environment and compiling from source is not practical.

> Use this repository only on systems you own or where you have explicit written authorization to test. Unauthorized use of these tools can be illegal and harmful.

---

## Contents

- [Purpose](#purpose)
- [Repository Layout](#repository-layout)
- [Tool Categories](#tool-categories)
- [Usage](#usage)
- [Verification and Safety](#verification-and-safety)
- [Adding New Binaries](#adding-new-binaries)
- [Recommended Metadata Format](#recommended-metadata-format)
- [Disclaimer](#disclaimer)
- [License Notice](#license-notice)

---

## Purpose

Security work often requires testing tools across restricted, offline, segmented, or lab environments where building tools from source is slow or not possible. This repository keeps frequently used binaries in one place so they can be referenced during:

- Internal penetration tests
- Red team exercises
- Active Directory security assessments
- Privilege-escalation validation
- Exploit proof-of-concept testing
- Post-exploitation lab simulation
- Tunneling, pivoting, and network reachability testing
- CTF, HTB, TryHackMe, and personal lab practice

This repository is not a replacement for the original tool projects. Always prefer the original upstream source when possible.

---

## Repository Layout

The repository contains binaries and related files organized by tool name, exploit name, or platform-specific folder.

Example structure:

```text
PrecompiledBinaries/
├── AccessChk/
├── Certify/
├── Chisel/
├── CVE-2021-3493/
├── CVE-2023-0386/
├── CVE-2024-20656/
├── DirtyPipe/
├── KrbRelayUp/
├── Ligolo-ng/
├── MimiKatz/
├── MultiPotato/
├── NetCat/
├── Nmap.exe/
├── PrintSpoofer/
├── ProcDump/
├── PsExec64/
├── Rubeus/
├── RunasCs/
├── SafetyKatz/
├── Seatbelt/
├── Sharp/
├── SharpWSUS/
├── StandIn/
├── Watson/
├── Linux/
├── socat/
└── rpivot/
```

Folder names may change as tools are added, replaced, renamed, or removed.

---

## Tool Categories

### Windows and Active Directory Assessment

Common binaries used for AD enumeration, Kerberos abuse testing, certificate service assessment, delegation testing, domain privilege review, and Windows environment discovery.

Examples include:

- `Rubeus`
- `Certify`
- `Seatbelt`
- `StandIn`
- `KrbRelayUp`
- `SharpWSUS`
- `SharpSuccessor`
- `BadSuccessor`
- `S4U`
- `PKInitmustiness`
- `kekeo`

### Credential and Memory Testing Utilities

Tools often used in controlled lab or authorized post-exploitation testing to validate credential exposure, LSASS protection, memory dumping controls, and endpoint monitoring behavior.

Examples include:

- `MimiKatz`
- `SafetyKatz`
- `Dumpert`
- `ProcDump`
- `pypykatz`

### Privilege Escalation and Exploit Validation

Binaries and proof-of-concept tools used to validate known misconfigurations or CVE exposure in authorized environments.

Examples include:

- `PrintSpoofer`
- `RogueWinRM`
- `MultiPotato`
- `Potatos`
- `Capcom`
- `DirtyPipe`
- `CVE-2021-3493`
- `CVE-2023-0386`
- `CVE-2024-20656`
- `cve-2018-8120-x64`
- `MS11-013`
- `MS14-068`

### Network, Pivoting, and File Transfer Utilities

Tools useful for controlled tunneling, relay testing, traffic forwarding, port exposure validation, and internal network reachability testing.

Examples include:

- `Chisel`
- `Ligolo-ng`
- `NetCat`
- `socat`
- `rpivot`
- `Nmap.exe`

### Sysinternals and Windows Administration Utilities

Common Windows utilities used for system inspection, process analysis, permission checks, and administrative testing.

Examples include:

- `AccessChk`
- `ProcDump`
- `Procmon64`
- `PsExec64`
- `Sigcheck.exe`

### Linux and Miscellaneous Binaries

Linux-focused or general-purpose binaries used during testing and lab workflows.

Examples include:

- `Linux`
- `whoami`
- `adduser.exe`
- `asktgs`
- `asktgt&s`
- `kerbstorm`
- `kirbikator`

---

## Usage

Clone the repository:

```bash
git clone https://github.com/h4rithd/PrecompiledBinaries.git
cd PrecompiledBinaries
```

Pull the latest updates:

```bash
git pull origin main
```

Download a single file from GitHub raw content:

```bash
curl -L -o <output-file> https://raw.githubusercontent.com/h4rithd/PrecompiledBinaries/main/<folder>/<binary>
```

Or with `wget`:

```bash
wget https://raw.githubusercontent.com/h4rithd/PrecompiledBinaries/main/<folder>/<binary> -O <output-file>
```

Replace `<folder>`, `<binary>`, and `<output-file>` with the required path and filename.

---

## Verification and Safety

Precompiled binaries are convenient, but they carry risk. Treat every binary as untrusted until verified.

Recommended checks before using any file:

```bash
file <binary>
sha256sum <binary>
strings <binary> | head
```

For Windows binaries, you can also inspect signatures and metadata:

```powershell
Get-FileHash .\binary.exe -Algorithm SHA256
Get-AuthenticodeSignature .\binary.exe
```

Before using any binary in a customer, company, or production-like environment:

- Confirm the original upstream project.
- Compare hashes with an official release where available.
- Check the binary architecture: x86, x64, ARM, Linux, or Windows.
- Test first in a disposable lab VM.
- Keep customer authorization and scope documented.
- Expect antivirus, EDR, and email gateways to flag many of these files.
- Do not execute binaries blindly on your own workstation.

---

## Adding New Binaries

When adding a new binary, include enough context so another tester can trust and verify it later.

Recommended contribution checklist:

- Use a clear folder name matching the tool or CVE.
- Include the original upstream URL in a `SOURCE.txt` or folder-level `README.md`.
- Add version, release date, build date, or commit hash where possible.
- Include SHA256 hash values.
- Mention target platform and architecture.
- Keep filenames simple and readable.
- Avoid duplicate binaries unless they are different versions or architectures.
- Do not add unknown files without provenance.
- Do not add commercial, leaked, stolen, or license-restricted binaries.

Suggested folder layout:

```text
ToolName/
├── README.md
├── SOURCE.txt
├── SHA256SUMS.txt
├── Windows-x64/
│   └── tool.exe
├── Windows-x86/
│   └── tool.exe
└── Linux-x64/
    └── tool
```

---

## Recommended Metadata Format

For better tracking, add a small `README.md` inside each tool folder using this format:

~~~markdown
# Tool Name

## Source

- Upstream: https://example.com/original/project
- Version: x.x.x
- Commit: `<commit-hash>`
- Downloaded or compiled date: YYYY-MM-DD

## Platform

- OS: Windows / Linux
- Architecture: x64 / x86 / ARM64
- Runtime requirements: .NET / Python / glibc / static

## Hashes

```text
SHA256  filename.exe  <hash>
```

## Notes

Short notes about build options, expected detections, or special requirements.
~~~

---

## Operational Notes

A few practical rules for real engagements:

- Keep a separate clean copy of this repository.
- Do not mix customer payloads, shells, logs, or evidence into this repo.
- Do not commit secrets, tokens, internal IPs, customer names, or payload callbacks.
- Use a private fork if you need customer-specific tooling.
- Keep offensive payloads and commodity tooling separated.
- Prefer signed and official binaries for administrative tools.
- Document what you used during an assessment.

---

## Disclaimer

This repository is provided for educational purposes, authorized security testing, research, and lab use only.

The owner of this repository is not responsible for misuse, damage, legal consequences, data loss, service disruption, or any unauthorized activity performed with files from this repository.

By using this repository, you agree that:

- You are responsible for your own actions.
- You will only use these tools where you have permission.
- You understand that many tools may be dual-use or offensive in nature.
- You will follow applicable laws, policies, and rules of engagement.

---

## License Notice

This repository may contain binaries from multiple third-party projects. Each tool may have its own license, redistribution terms, and usage restrictions.

Unless a separate `LICENSE` file is provided for this repository and each included tool, do not assume that all binaries share the same license.

Before redistributing, modifying, or using any binary commercially, verify the license of the original upstream project.

---

## Maintainer

Maintained by [h4rithd](https://github.com/h4rithd).

For updates, issues, or improvements, open a pull request or create an issue in the repository.
